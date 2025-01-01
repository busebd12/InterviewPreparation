#Both solutions inspired by this post: https://leetcode.com/problems/number-of-music-playlists/solutions/1637225/recursive-definition-with-detailed-explanation/

#Solution 1: this solution is just pure recursion and will receive Time Limit Exceed when run. DO NOT submit this one!!!
#I have added it just so it's clear what the recursion + memoization solution is derived from.
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        result: int=0

        MOD: int=pow(10, 9) + 7

        total_songs: int=0

        unique_songs: int=0

        result=self.solve(n, goal, k, MOD, total_songs, unique_songs)

        return result

    def solve(self, n: int, goal: int, k: int, MOD: int, total_songs: int, unique_songs: int) -> int:
        if total_songs==goal:
            return unique_songs==n

        subproblem_solution: int=0

        if unique_songs < n:
            next: int=(n - unique_songs) * self.solve(n, goal, k, MOD, total_songs + 1, unique_songs + 1)

            subproblem_solution+=next

            subproblem_solution%=MOD

        if unique_songs > k:
            next: int=(unique_songs - k) * self.solve(n, goal, k, MOD, total_songs + 1, unique_songs)

            subproblem_solution+=next

            subproblem_solution%=MOD

        return subproblem_solution

#Solution 2: Recursive memoization solution
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        result: int=0

        memo: List[List[int]]=[[-1 for _ in range(0, goal + 1)] for _ in range(0, n + 1)]

        MOD: int=pow(10, 9) + 7

        total_songs: int=0

        unique_songs: int=0

        result=self.solve(memo, n, goal, k, MOD, total_songs, unique_songs)

        return result

    def solve(self, memo: List[List[int]], n: int, goal: int, k: int, MOD: int, total_songs: int, unique_songs: int) -> int:
        if total_songs==goal:
            return unique_songs==n

        if memo[unique_songs][total_songs]!=-1:
            return memo[unique_songs][total_songs]

        subproblem_solution: int=0

        #If unique_songs < n, then there are still songs that haven't been played yet, available in the music player, that we can add to the playlist
        if unique_songs < n:

            #The number of songs remaining in the music player that have not been played at all
            remaining_songs: int=n - unique_songs
            
            #To get the number of playlists, we have to multiply remaining_songs by the recursive call to the solve function
            next: int=remaining_songs * self.solve(memo, n, goal, k, MOD, total_songs + 1, unique_songs + 1)

            subproblem_solution+=next

            subproblem_solution%=MOD

        #If unique songs in the playlist is greater than k, then we can re-play a song that was played before
        if unique_songs > k:

            #The number of songs that can be played again in the playlist is equal to the number of unique_songs
            #played so far minus k since we have to play k different songs before repeating a song
            reusable_songs: int=unique_songs - k
            
            #To get the number of playlists, we have to multiply reusable_songs by the recursive call to the solve function
            next: int=reusable_songs * self.solve(memo, n, goal, k, MOD, total_songs + 1, unique_songs)

            subproblem_solution+=next

            subproblem_solution%=MOD

        memo[unique_songs][total_songs]=subproblem_solution

        return subproblem_solution