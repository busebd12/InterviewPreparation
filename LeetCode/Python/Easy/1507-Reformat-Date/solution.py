class Solution:
    def reformatDate(self, date: str) -> str:
        date_hashmap: List[str]=[str(number) for number in range(0, 32)]

        month_hashmap: Dict[str, str]={"Jan":"01", "Feb":"02", "Mar":"03", "Apr":"04", "May":"05", "Jun":"06", "Jul":"07", "Aug":"08", "Sep":"09", "Oct":"10", "Nov":"11", "Dec":"12"}

        parts: List[str]=date.split(" ")

        day: str=""

        if len(parts[0]) == 4:
            day=date_hashmap[int(parts[0][0:2])]
        else:
            day="0" + date_hashmap[int(parts[0][0:1])]

        month: str=month_hashmap[parts[1]]

        year: str=parts[2]

        separator: chr='-'

        return separator.join((year, month, day))