class TopVotedCandidate {
public:
    map<int, int> m2;
    unordered_map<int, int> m;
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		int lead = -1;
		m[-1] = 0;
		int n = persons.size();
		for (int i = 0; i < n; ++i) {
			m[persons[i]]++;
			if (m[persons[i]] >= m[lead]) lead = persons[i];
			m2[times[i]] = lead;
		}
	}

	int q(int t) {
		return (*(--m2.upper_bound(t))).second;
	}
};