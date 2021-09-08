/**
 * 暴力破解法
 *  可以把turned分为可能的hour和minute，双重循环解决
 */
class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> rst = new ArrayList(16);

        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (bitCount(hour) + bitCount(minute) == turnedOn) {
                    rst.add(String.valueOf(hour) + ":" + (minute > 9 ? minute : "0" + minute));            
                }
            }
        }

        return rst;
    }

    public int bitCount(int num) {
        int ret = 0;
        while (num > 0) {
            if ((num & 0x1) == 1) {
                ret++;
            }
            num = num >> 1;
        }
        return ret;
    }
}
