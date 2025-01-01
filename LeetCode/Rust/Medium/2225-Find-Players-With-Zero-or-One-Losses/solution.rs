impl Solution
{
    pub fn find_winners(matches: Vec<Vec<i32>>) -> Vec<Vec<i32>>
    {
        let mut result: Vec<Vec<i32>>=Vec::new();

        let max_players: usize=usize::pow(10, 5) + 1;

        let mut matches_lost: Vec<i32>=vec![0; max_players];

        let mut played_matches: Vec<bool>=vec![false; max_players];

        for _match in matches.iter()
        {
            let winner: i32=_match[0];

            let loser: i32=_match[1];

            matches_lost[loser as usize]+=1;

            played_matches[winner as usize]=true;

            played_matches[loser as usize]=true;
        }

        let mut undefeated: Vec<i32>=Vec::new();

        let mut only_lost_one: Vec<i32>=Vec::new();

        for player in 0..max_players
        {
            if played_matches[player]==true
            {
                match matches_lost[player]
                {
                    0 =>
                    {
                        undefeated.push(player as i32);
                    },
                    1 =>
                    {
                        only_lost_one.push(player as i32);
                    },
                    _ =>
                    {
                        ()
                    }
                }
            }
        }

        result.push(undefeated);

        result.push(only_lost_one);

        result
    }
}