impl Solution
{
    pub fn game_result(head: Option<Box<ListNode>>) -> String
    {
        let mut result: String=String::from("Tie");

        let mut current: &Option<Box<ListNode>>=&head;

        let mut even_score: i32=0;

        let mut odd_score: i32=0;

        while let Some(node)=current
        {
            if let Some(next_node)=&node.next
            {
                if node.val > next_node.val
                {
                    even_score+=1;
                }
                else if next_node.val > node.val
                {
                    odd_score+=1;
                }

                current=&next_node.next;
            }
            else
            {
                break;
            }
        }

        if even_score!=odd_score
        {
            if even_score > odd_score
            {
                result="Even".to_string();
            }
            else
            {
                result="Odd".to_string();
            }
        }

        result
    }
}