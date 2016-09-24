public class NumArray {
    int [] BIT;
    int [] originNode;
    int MaxLength;
    int lowbit(int x){
        return x & -x;
    }
    public NumArray(int[] nums) {
        BIT = new int[nums.length + 1];
      	originNode = new int[nums.length];
        MaxLength = nums.length;
        for(int i = 0; i < nums.length; ++i){
            update(i, nums[i]);
        }
    }
    private int getOrigin(int x){
        return originNode[x];
    }
    
    private void setOrigin(int x, int val){
         originNode[x] = val;
    }
    public int get(int x){
        int sum = 0;
        while(x > 0){
            sum += BIT[x];
            x -= lowbit(x);
        }
        return sum;
    }
    void change(int x, int val){
        x += 1;
        while(x <= MaxLength){
            BIT[x] += val;
            x += lowbit(x);
        }
    }
    void update(int i, int val) {
        int ori = getOrigin(i);
        int diff = val - ori;
        setOrigin(i, val);
        change(i, diff);
    }

    public int sumRange(int i, int j) {
        return get(j + 1) - get(i);
    }
}