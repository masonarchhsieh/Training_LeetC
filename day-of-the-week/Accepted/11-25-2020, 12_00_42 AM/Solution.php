// https://leetcode.com/problems/day-of-the-week

class Solution {

    /**
     * @param Integer $day
     * @param Integer $month
     * @param Integer $year
     * @return String
     */
    function dayOfTheWeek($day, $month, $year) {
        return date("l", strtotime( "$day" . '-' . "$month" . '-' . "$year"));
    }
}