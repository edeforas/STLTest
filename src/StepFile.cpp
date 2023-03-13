#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "StepFile.h"




namespace StepFile
{   
    class StepLine
    {
    public:
        StepLine(string s)
        {
            from_string(s);
        }

        void from_string(string s)
        {
            if (s[0] != '#')
                return;
            int iPosEqual = s.find('=');
            _id = atoi(s.substr(1, iPosEqual).c_str());

        }

        int _id;
        string _type;
    };

    bool save(const string& filename, const NurbsSurface& surf)
    {
        ofstream f(filename);
        if (!f)
            return false;

  
        return false;
    }
    ///////////////////////////////////////////////////////////////////////////
	bool load(const string& filename, NurbsSurface& surf)
    {
        surf.clear();
        ifstream f(filename);
        if (!f)
            return false;

        vector<StepLine> vs;

        bool bDataReady = false;

        // read all lines
        while (!f.eof())
        {
            string sType, sLine;
            getline(f, sLine);

            if (sLine.size() == 0)
                continue;

            //skip header
            if (sLine == "DATA;")
                bDataReady = true;
            if (bDataReady == false)
                continue;

            //read full line
            while (sLine[sLine.size() - 1] != ';')
            {
                string s;
                if (f.eof())
                    return false;
                getline(f, s);
                sLine += s;
            }

            vs.push_back(StepLine(sLine));
        }

        return true;
    }
    ///////////////////////////////////////////////////////////////////////////
}