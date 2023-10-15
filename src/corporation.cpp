#include "corporation.h"

using namespace std;

Tree<string> makeCorporationTree()
{
    return {
        {"Electronics 'R' Us", {
            {"R&D"},
            {"Sales", {
                {"Domestic"},
                {"International", {
                    {"Canada"},
                    {"S. America"},
                    {"Overseas", {
                        {"Africa"},
                        {"Europe"},
                        {"Asia"},
                        {"Australia"},
                    }},
                }},
            }},
            {"Purchasing"},
            {"Manufacturing", {
                {"TV"},
                {"CD"},
                {"Tuner"},
            }},
        }}
    };
}
