use rust_dp::Solution;
fn main() {
    assert!(1 == Solution::coin_change(vec![5, 3, 4, 7], 7));
    assert!(2 == Solution::coin_change(vec![2, 3, 5], 8));
    assert!(2 == Solution::coin_change(vec![1, 4, 5], 8));
    assert!(-1 == Solution::coin_change(vec![2], 3));
    assert!(0 == Solution::coin_change(vec![1], 0));
    assert!(20 == Solution::coin_change(vec![1, 2, 5], 100));
}
