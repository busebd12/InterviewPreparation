class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        result=list()

        max_players=(10**5) + 1

        matches_lost=[0 for _ in range(0, max_players)]

        played_matches=[False for _ in range(0, max_players)]

        for match in matches:
            winner=match[0]

            loser=match[1]

            matches_lost[loser]+=1

            played_matches[winner]=True

            played_matches[loser]=True

        undefeated=list()

        for player in range(0, max_players):
            if matches_lost[player]==0 and played_matches[player]:
                undefeated.append(player)

        result.append(undefeated)

        only_lost_one=list()

        for player in range(0, max_players):
            if matches_lost[player]==1 and played_matches[player]:
                only_lost_one.append(player)

        result.append(only_lost_one)

        return result