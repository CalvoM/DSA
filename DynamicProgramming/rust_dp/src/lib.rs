use std::{cmp::Ordering, collections::HashMap};

pub struct Solution {}
impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let mut memo: HashMap<i32, Option<Vec<i32>>> = HashMap::new();
        let res = Solution::_coin_change(&coins, amount, &mut memo);
        if let Some(ans) = res {
            ans.len() as i32
        } else {
            -1
        }
    }
    fn _coin_change(
        coins: &Vec<i32>,
        amount: i32,
        memo: &mut HashMap<i32, Option<Vec<i32>>>,
    ) -> Option<Vec<i32>> {
        if memo.contains_key(&amount) {
            if let Some(ret_val) = memo.get(&amount) {
                ret_val.clone()
            } else {
                None
            }
        } else {
            match amount.cmp(&0) {
                Ordering::Equal => Some(vec![]),
                Ordering::Less => None,
                Ordering::Greater => {
                    let mut short_combination: Option<Vec<i32>> = None;
                    let mut diff = amount;
                    for coin in coins {
                        diff = amount - coin;
                        let res = Solution::_coin_change(coins, diff, memo);
                        if let Some(res_) = res {
                            let mut combination: Vec<i32> = vec![*coin];
                            combination.extend(res_);
                            match short_combination {
                                None => short_combination = Some(combination),
                                Some(ref _short_combination) => {
                                    if _short_combination.len() > combination.len() {
                                        short_combination = Some(combination);
                                    }
                                }
                            }
                        }
                    }
                    memo.insert(amount, short_combination.clone());
                    short_combination
                }
            }
        }
    }
    pub fn convert_time(current: String, correct: String) -> i32 {
        let cur_hh_mm = Solution::extract_time(current);
        let correct_hh_mm = Solution::extract_time(correct);
        let amount = (correct_hh_mm[0] - cur_hh_mm[0]) * 60 + (correct_hh_mm[1] - cur_hh_mm[1]);
        Solution::coin_change(vec![1, 5, 15, 60], amount)
    }
    fn extract_time(time_str: String) -> Vec<i32> {
        let hh_mm: Vec<&str> = time_str.split(':').collect();
        hh_mm.iter().map(|x| x.parse::<i32>().unwrap()).collect()
    }
}
