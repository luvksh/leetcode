https://leetcode.com/problems/basic-calculator/
class Solution
{
private:
	string st;
	string::iterator i;
	string token;
public:
	int calculate(string s)
	{
		st = s;
		i = st.begin();
		nextToken();
		return S();
	}
	int S()
	{
		int res = T();
		while (token == "+" || token == "-")
		{
			char oper = token.c_str()[0];
			nextToken();
			int op2 = T();
			switch (oper)
			{
			case '+': res += op2;
				break;
			case '-': res -= op2;
				break;
			}
		}
		return res;
	}
	int T()
	{
		int res;
		if (isNumber(token))
		{
			res = atoi(token.c_str());
			nextToken();
		}
		else if (token == "(")
		{
			nextToken();
			res = S();
			if (token == ")")
				nextToken();
			else
			{
				printf("Expected )");
			}
		}
		return res;
	}
	bool isNumber(string s)
	{
		for (char c : s)
		{
			if (!isdigit(c))
				return false;
		}
		return true;
	}
	void nextToken()
	{
		token.clear();
		if (i == st.end())
			return;
		while (*i == ' ')
		{
			i++;
		}
		if (isdigit(*i))
		{
			while(i != st.end() && isdigit(*i))
			{
				token.push_back(*i);
				i++;
			}
		}
		else
		{
			token.push_back(*i++);
		}
	}
};