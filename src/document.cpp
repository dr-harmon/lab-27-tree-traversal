#include "document.h"

using namespace std;

Tree<string> makeDocumentTree()
{
    return {
        {"Paper", {
            {"Title"},
            {"Abstract"},
            {"§ 1", {
                {"§ 1.1"},
                {"§ 1.2"},
            }},
            {"§ 2", {
                {"§ 2.1"},
                {"§ 2.2"},
                {"§ 2.3"},
            }},
            {"§ 3", {
                {"§ 3.1"},
                {"§ 3.2"},
            }},
            {"References"},
        }}
    };
}

