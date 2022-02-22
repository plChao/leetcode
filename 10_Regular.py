import sys
dfa_path = {}
class Solution(object):
    def create_nfa(self, pattern):
        index = 0
        state_index = 0
        dfa_path[0] = {}
        while index < len(pattern):
            c = str(pattern[index])
            if index+1 < len(pattern) and str(pattern[index+1]) == '*':
                if c == '.':
                    try:
                        dfa_path[state_index]['.'].add(state_index)
                    except:
                        dfa_path[state_index]['.'] = set([state_index])
                else:
                    try:
                        dfa_path[state_index][c].add(state_index)
                    except:
                        dfa_path[state_index][c] = set([state_index])
                try:
                    dfa_path[state_index]['E'].add(state_index+1)
                except:
                    dfa_path[state_index]['E'] = set([state_index+1])
                state_index += 1
                dfa_path[state_index] = {}
                index += 1
            else:
                if c == '.':
                    try:
                        dfa_path[state_index]['.'].add(state_index + 1)
                    except:
                        dfa_path[state_index]['.'] = set([state_index + 1])
                else:
                    try:
                        dfa_path[state_index][c].add(state_index + 1)
                    except:
                        dfa_path[state_index][c] = set([state_index + 1])
                state_index += 1
                dfa_path[state_index] = {}
            index += 1
        return state_index
    def operate_nfa(self, s, end_state):
        state_list = set([0])
        for c in s:
            pre_len = -1
            while pre_len != len(state_list):
                pre_len = len(state_list)
                next_state_list = state_list.copy()
                for state in state_list:
                    try:
                        next_state_list.update(dfa_path[state]['E'])
                    except:
                        pass
                state_list = next_state_list
            next_state_list = set()
            for state in state_list:
                try:
                    next_state_list.update(dfa_path[state][c])
                except:
                    pass
                try:
                    next_state_list.update(dfa_path[state]['.'])
                except:
                    pass
            state_list = next_state_list
        pre_len = -1
        while pre_len != len(state_list):
            pre_len = len(state_list)
            next_state_list = state_list.copy()
            for state in state_list:
                try:
                    next_state_list.update(dfa_path[state]['E'])
                except:
                    pass
            state_list = next_state_list
        if end_state in state_list:
            return True
        else:
            return False
                
                
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        end_state = self.create_nfa(p)
        print(dfa_path, end_state)
        return self.operate_nfa(s, end_state)

if len(sys.argv) > 2:
    S = Solution()
    print(S.isMatch(sys.argv[1], sys.argv[2]))
else:
    print('ex.py string pattern')