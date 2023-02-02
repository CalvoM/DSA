#[derive(Debug)]
pub struct Node {
    value: u64,
    next: Option<Box<Node>>,
}

impl Node {
    pub fn new(value: u64, next: Option<Box<Node>>) -> Node {
        Node { value, next }
    }
}
