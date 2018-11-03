
class WordCounter
  def initialize(file_name)
    @file = File.read(file_name).downcase
    
  end

  def count
  	@num = @file.split(/\W+/).length()
  end

  def uniq_count
  	@uniq_num = @file.split(/\W+/).uniq.length()
  end

  def frequency
  	ary = @file.split(/\W+/)
  	freq = Hash.new
  	ary.each do |word|
  		if freq.has_key?(word)
  			freq[word] = freq[word] + 1
  		else
  			freq[word] = 1
  		end
  	end

    freq.each do |key, value|
      print key, " appears ", value, " times.\n"
    end
  	
  end

end
