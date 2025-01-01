class Solution:
    #Hashmap mapping a skill to a list of indices representing people
    __skill_to_people: dict[str, list[int]]=None
    #Hashmap mapping the index of a person to their set of skills
    __person_to_skills: dict[int, set[str]]=None
    #Result list to be returned
    __result: list[int]=None
    
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        self.__skill_to_people=self.build_skill_to_people(req_skills, people)

        self.__person_to_skills=self.build_person_to_skills(people)

        self.__result=list()

        n: int=len(req_skills)

        p: int=len(people)

        skills_needed: set[str]=set(req_skills)

        index: int=0

        team: list[int]=list()

        self.helper(req_skills, skills_needed, team, index)

        return self.__result

    def build_skill_to_people(self, req_skills: list[str], people: list[list[str]]) -> dict[int, set[str]]:
        hashmap: dict[str, list[int]]=dict()
        
        for skill in req_skills:
            hashmap[skill]=list()

        for index in range(0, len(people)):
            for skill in people[index]:
                hashmap[skill].append(index)

        return hashmap

    def build_person_to_skills(self, people: list[list[str]]) -> dict[int, set[str]]:
        hashmap: dict[int, set[str]]=dict()
        
        for person, skills in enumerate(people):
            hashmap[person]=set(skills)

        return hashmap

    def helper(self, req_skills: list[str], skills_needed: set[int], team: List[int], index: int) -> None:
        #If we have found all the needed skills
        if not skills_needed:
            #If the current team is smaller than the smallest team we have found so far
            if len(team) < len(self.__result) or not self.__result:
                #Override self.__result with the current team
                #IMPORTANT: we use the team[:] syntax instead of just team so that self.__result
                #and team will refer to different places in memory, and any further changes to team will not be applied to self.__result
                self.__result=team[:]

            return
        #The current skill we are looking for
        skill: str=req_skills[index]

        #If the current skill is not in the set (someone on the team already has the current skill)
        if skill not in skills_needed:
            #Recurse for the next skill
            self.helper(req_skills, skills_needed, team, index + 1)
        #Else, we need to find someone with this skill
        else:
            #Loop through all the people that have this skill
            for person in self.__skill_to_people[skill]:
                #Add the person to the team
                team.append(person)

                #Create the intersection of the sets shared_skills and the set of skills for the current person
                shared_skills: set[int]=skills_needed.intersection(self.__person_to_skills[person])

                #Remove the intersection of skills from the skills_needed set
                #We do this because the person we just picked if there is more than one skill
                #in the intersection, then we can get more than one skill from this one person
                #and this will help us minimize the size of the team
                skills_needed.difference_update(shared_skills)

                #Recurse for the next skill
                self.helper(req_skills, skills_needed, team, index + 1)

                #Backtracking step: added the skills we removed from skills_needed back into skills_needed
                skills_needed.update(shared_skills)
                
                #Backtracking step: remove the person we just added to the team from the team
                team.pop()