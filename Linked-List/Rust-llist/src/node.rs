#[derive(Debug)]
pub struct Node {
    pub value: u64,
    pub next: Option<Box<Node>>,
}

impl Node {
    pub fn new(value: u64, next: Option<Box<Node>>) -> Node {
        Node { value, next }
    }
}

pub struct LinkedList {
    head: Option<Box<Node>>,
}

impl LinkedList {
    pub fn new() -> LinkedList {
        LinkedList { head: None }
    }

    pub fn add_to_front(&mut self, value: u64) {
        let node = Node::new(value, None);
        if self.head.is_some() {
            node.next = self.head;
        } else {
            self.head = Some(Box::new(node));
        }
    }
}
