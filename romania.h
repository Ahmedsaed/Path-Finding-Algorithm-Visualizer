#ifndef ROME_H
#define ROME_H

#include <map>
#include <string>
#include <utility>
#include "vector.h"

std::map<std::string, udtl::vector<std::pair<std::string, int>>> romania = {
	{"Arad", {{"Sibiu",140}, {"Zerind",75}, {"Timisoara",118}}}, 
	{"Zerind", {{"Arad",75}, {"Oradea",71}}},
	{"Oradea", {{"Zerind",71}, {"Sibiu",151}}},
	{"Sibiu", {{"Arad",140}, {"Oradea",151}, {"Fagaras",99}, {"Rimnicu Vilcea",80}}},
	{"Timisoara", {{"Arad",118}, {"Lugoj",111}}},
	{"Lugoj", {{"Timisoara",111}, {"Mehadia",70}}},
	{"Mehadia", {{"Lugoj",70}, {"Drobeta",75}}},
	{"Drobeta", {{"Mehadia",75}, {"Craiova",120}}},
	{"Craiova", {{"Drobeta",120}, {"Rimnicu Vilcea",146}, {"Pitesti",138}}},
	{"Rimnicu Vilcea", {{"Sibiu",80}, {"Craiova",146}, {"Pitesti",97}}},
	{"Fagaras", {{"Sibiu",99}, {"Bucharest",211}}},
	{"Pitesti", {{"Rimnicu Vilcea",97}, {"Craiova",138}, {"Bucharest",101}}},
	{"Bucharest", {{"Fagaras",211}, {"Pitesti",101}, {"Giurgiu",90}, {"Urziceni",85}}},
	{"Giurgiu", {{"Bucharest",90}}},
	{"Urziceni", {{"Bucharest",85}, {"Vaslui",142}, {"Hirsova",98}}},
	{"Hirsova", {{"Urziceni",98}, {"Eforie",86}}},
	{"Eforie", {{"Hirsova",86}}},
	{"Vaslui", {{"Iasi",92}, {"Urziceni",142}}},
	{"Iasi", {{"Vaslui",92}, {"Neamt",87}}},
	{"Neamt", {{"Iasi",87}}}
};

std::map<std::string, int> H_table = {
    {"Arad", 366},
    {"Zerind", 374},
    {"Oradea", 380},
    {"Sibiu", 253},
    {"Timisoara",329 },
    {"Lugoj", 244},
    {"Mehadia", 241},
    {"Drobeta", 242},
    {"Craiova", 160},
    {"Rimnicu Vilcea", 193},
    {"Fagaras", 178},
    {"Pitesti", 98},
    {"Bucharest", 0},
    {"Giurgiu", 77},
    {"Urziceni", 80},
    {"Hirsova", 151},
    {"Eforie", 161},
    {"Vaslui", 199},
    {"Iasi", 226},
    {"Neamt", 234}
};

#endif
