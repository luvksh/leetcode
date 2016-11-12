class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        string line = "";
        int ctr = 0;
        bool firstWord = true;
        bool lineHoldsValue = false;
        for(auto si = words.begin(); si != words.end(); si++)
        {
            ctr+=si->size();
            if(!firstWord)
                ctr++;
            if(ctr == maxWidth)
            {
                if(!firstWord)
                    line.append(" ");
                line.append(*si);
                firstWord = true;
                result.push_back(line);
                line = "";
                ctr = 0;
                lineHoldsValue = false;
            }
            else if( ctr > maxWidth)
            {
                string temp = justify(line, maxWidth);
                result.push_back(temp);
                line="";
                firstWord = true;
                ctr = 0;
                si--;
                lineHoldsValue = false;
            }
            else
            {
                if(!firstWord)
                    line.append(" ");
                line.append(*si);
                lineHoldsValue = true;
                firstWord = false;
            }
        }
        if(lineHoldsValue)
        {
            string spaces(maxWidth-ctr, ' ');
            line.append(spaces);
            result.push_back(line);
        }
        return result;
    }
    
    string justify(string& line, int width)
    {
        string result = "";
        int numOfSpaces = 0;
        int totalSpaces = width-line.size();
        int numOfSpacesPerInst;
        int numRemSpaces;
        for(char ch:line)
        {
            if(ch == ' ')
                numOfSpaces++;
        }
        if (numOfSpaces == 0)
        {
            result.append(line);
            string spaces(totalSpaces, ' ');
            result.append(spaces);
        }
        else
        {
            numOfSpacesPerInst = totalSpaces/numOfSpaces;
            string spaces(numOfSpacesPerInst+1, ' ');
            numRemSpaces = totalSpaces%numOfSpaces;
            for(char ch:line)
            {
                if(ch != ' ')
                    result.append(1 , ch);
                else
                {
                    result.append(spaces);
                    if(numRemSpaces)
                    {
                        result.append(" ");
                        numRemSpaces--;
                    }
                }
            }
        }
        return result;
    }
};