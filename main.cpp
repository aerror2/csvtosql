//
//  Created by aerror on 2020/9/16.
//  Copyright © 2020 dany. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    if(argc < 3)
    {
        std::cout << argv[0] << " filename.csv table " << "\n";
        return -1;
    }
    
    std::string filename =argv[1];
    std::string tablename =argv[2];

      try
        {
            std::ifstream fi(filename);
            if(fi.bad() || fi.fail())
            {
                std::cout << "open config.txt failed" <<std::endl;
                return -1;
            }
    
            unsigned long  x = 0;
            bool hasend = false;
            while(!fi.eof())
            {
                std::string s1;
                getline(fi,s1);
                if(s1.empty()) continue;
                
                unsigned long   m = x % 1000 ;
                if(m == 0)
                {
                    std::cout << "INSERT INTO `"<<tablename<<"` VALUES ";
                    hasend = false;
                }
                else
                {
                   std::cout << ",";
                }
                
                size_t npos = s1.find("\\N,\\N");
                if(npos!=std::string::npos)
                {
                    std::cout << "(" << s1.replace(npos, npos+5, "\"\",0") << ")";
                }
                else
                {
                    std::cout << "(" << s1 << ")";
                }
               
                
                
                if(m==999)
                {
                    std::cout << ";" << "\n";
                    hasend = true;
                }
                
                x++;
            }
            
            if(!hasend)
            {
                   std::cout << ";" << "\n";
            }
        }
        catch(...)
        {
                std::cout << "is not ok"<<std::endl;
        }
    return 0;
}
