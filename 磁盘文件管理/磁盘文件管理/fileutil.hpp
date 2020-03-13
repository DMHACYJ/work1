#pragma once
#include<string>
#include<io.h>
#include<iostream>
#include<vector>
#include<unordered_set>
void searchDir(const std::string& path, std::unordered_set<std::string>& subFiles);
void deleteFile(const char* filename);