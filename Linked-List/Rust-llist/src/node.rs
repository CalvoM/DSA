pub enum Node{
    Cell(u32, Box<Node>),
    Nil
}