public class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null){
            return head;
        }
        ListNode tail = head, cur, prev;
        int count = 1;
        while(tail.next != null){
            count ++;
            tail = tail.next;
        }
        tail.next = head;
        k %= count;
        k = count - k;
        // System.out.println(count);
        // System.out.println(k);
        // System.out.println();
        cur = head;
        prev = tail;
        while(k > 0){
            k--;
            cur = cur.next;
            prev = prev.next;
        }
        prev.next = null;
        return cur;
    }
}
