//
//    Game Project -> Space Strategy
//
//    RessourceLinker.cpp
//    copyrights by Lukas Guz
//

#include "RessourceLinker.h"

//constructor
RessourceLinker::RessourceLinker(){

}

// LoadResources
void RessourceLinker::LoadResources(std::string fileType, std::string nameObject){

   // prepares the Type to be a file path
   fileType = fileType.append(".txt");
   fileType = fileType.insert(0,"Resources/");

   // opends the needed file by FileType(prepared)
   std::ifstream file;        // variable file that can use the needed functions
   file.open(fileType);       // open the needed file

   // prints error code if file was not opened correctly
   if (!file){
      printf("Error in Reading: %s\n", fileType.c_str());
   }else{

      // reading file and put this in variable lines
      std::string lines;
      unsigned int curRow = 0;

      while(std::getline(file, lines)){
         //search for the requested Object
         if (lines.find(nameObject) != std::string::npos){
            std:size_t pos = lines.find('"');
            _filePath = lines.substr(pos);
            printf("Error test %s\n", _filePath.c_str());
         }
         // next line:
         curRow++;
      }
   }
   file.close();

}
