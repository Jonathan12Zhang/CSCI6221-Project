abstract class State{
    public abstract String getState();
}
class Single extends State{
    public String getState(){
        return "single";
    }
}
class Married extends State{
    private Person spouse;
    Married(Person spouse){
        this.spouse = spouse;
    }
    public String getState(){
        return "married";
    }
}
class Divorced extends State{
    public String getState(){
        return "divorced";
    }
}
class Widow extends State{
    public String getState(){
        return "widow";
    }
}

class Person{
    private State mystate;
    public Person(){
        this.mystate = new Single();
    }
    public String getMyState(){
        return mystate.getState();
    }
    public void getMarried(Person spouse){
        if(mystate.getState().equals("married")){
            System.out.println("You have already been married! Please divorce first!");
        }else{
            mystate = new Married(spouse);
            System.out.println("Happy wedding!!!");
        }
    }
    public void divorce(){
        if(mystate.getState().equals("married")){
            mystate = new Divorced();
            System.out.println("Welcome back to single life!");
        }else{
            System.out.println("I'm so sorry, you have no one to divorce with.");
        }
    }
    public void widow(){
        if(mystate.getState().equals("married")){
            mystate = new Widow();
            System.out.println("Who is the murderer?");
        }else{
            System.out.println("You have no partner to die! You devil!");
        }
    }
}

// due to the rule of CodeChef, I need to change the name of public class to 'Main' instead of 'Client'
public class Main{
    public static void main(String[] args){
        Person p = new Person();
        System.out.println("The person is born!");
        // check the initial state, it should be single.
        System.out.print("Now check the initial state of the person: ");
        System.out.println("This person's initial state is: " + p.getMyState());
        // Single can not widow or divorce
        System.out.print("Try to divorce: ");
        p.divorce();
        System.out.print("Try to widow: ");
        p.widow();
        // check if state is still single
        System.out.print("Now check the single person's state after divorce and widow: ");
        System.out.println("This person's state is still: " + p.getMyState());
        // Single can get married
        Person spouse = new Person();
        System.out.println("Try to get married: ");
        p.getMarried(spouse);
        spouse.getMarried(p);
        // check if state becomes married
        System.out.print("Check the two people's state after get married: ");
        System.out.print("This person's state is now: " + p.getMyState() + ", ");
        System.out.println("the spouse's state is now: " + spouse.getMyState());
        // Married person cannot married
        System.out.print("Try to get married again: ");
        p.getMarried(spouse);
        // Married person can divorce and widow
        // check the state of the two person
        System.out.print("Use person to test the divorce method: ");
        p.divorce();
        System.out.println("This person's state is now: " + p.getMyState());
        System.out.print("Use spouse to test the widow method: ");
        spouse.widow();
        System.out.println("The spouse's state is now: " + spouse.getMyState());
        // divorced person and widowed person can married again
        System.out.println("divorced person and widowed person can married again: ");
        p.getMarried(spouse);
        spouse.getMarried(p);
        System.out.print("This person's state is now: " + p.getMyState() + ", ");
        System.out.println("the spouse's state is now: " + spouse.getMyState());
    }
}