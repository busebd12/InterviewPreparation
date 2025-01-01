class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        alice_groups: int=0

        bob_groups: int=0

        n: int=len(colors)

        for index in range(1, n - 1):
            if colors[index]=='A':
                if colors[index - 1]=='A' and colors[index + 1]=='A':
                    alice_groups+=1
            else:
                if colors[index - 1]=='B' and colors[index + 1]=='B':
                    bob_groups+=1

        return False if alice_groups <= bob_groups else True