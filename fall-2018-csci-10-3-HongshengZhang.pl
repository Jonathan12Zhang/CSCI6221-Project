open(DATA, "$ARGV[0]") or die "apache.logs cannot open, $!";
@lines = <DATA>;
close(DATA);
$size=@lines;
@dateOfMay=(0,0);
for($i=0;$i<31;$i=$i+1){
    $dateOfMay[$i]=0;
}

for($i=0;$i<$size;$i=$i+1){
    $lines[$i]=~m/\"\s\d\d\d/;
    $staus="$&";
    $staus=~m/\d\d\d/;
    $stausnum="$&";
    if($stausnum==200){  
        if($lines[$i]=~m/\d+\/May\/2015/){
            $lines[$i]=~m/\d+\/May\/2015/;
            $s="$&";
            $s=~m/\//;
            $date="$`";
            $dateOfMay[$date-1]=$dateOfMay[$date-1]+1;
        }
    }
}

use List::Util qw/max
min/;
$Max=max @dateOfMay;
$Min=min @dateOfMay;

@sortdate=sort { $a <=> $b }  @dateOfMay;
$medain=$sortdate[15];

use List::Util qw/sum/;
$sum=sum @dateOfMay;
$average=$sum/31;
$variance=0;
for($i=0;$i<31;$i=$i+1){
    $variance=$variance+($dateOfMay[$i]-$average)**2;
}
$std=sqrt($variance/31);

print "Max=$Max\n";
print "Min=$Min\n";
print "Medain=$medain\n";
print "Average=$average\n";
print "Standard Deviation=$std\n";