public class Solution {
	
	public int lengthOfLongestSubstring(String s) {
		if(s == null || s.length() == 0)
			return 0;
		if(s.length() == 1)
			return 1;
		
		int length = 0;
		Set<Character> set = new HashSet<>();
		for(int out=0;out<s.length();out++) {
			for(int i=out;i<s.length();i++) {
				if(set.contains(s.charAt(i))) {
					if(set.size() > length) {
						length = set.size();
					}
					set.clear();
					break;
				} else {
					set.add(s.charAt(i));
				}
			}
		}
		
		return length;
    }
	
}

