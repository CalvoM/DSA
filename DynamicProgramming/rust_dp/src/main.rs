use rust_dp::Solution;
fn main() {
    Solution::coin_change(vec![5, 3, 4, 7], 7);
    Solution::coin_change(vec![2, 3, 5], 8);
    Solution::coin_change(vec![1, 4, 5], 8);
    Solution::coin_change(vec![2], 3);
    Solution::coin_change(vec![1], 0);
    Solution::coin_change(vec![1, 2, 5], 100);
    assert!(3 == Solution::coin_change(vec![1, 5, 15, 60], 125));
}
