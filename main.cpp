#include "Huffman.h"

int main()
{
    Huffman huffman;

    int choose;

//    huffman.getMap();
//    huffman.showMap();

    while(true)
    {
        cout << "[1] Input Huffman hash map" << endl;
        cout << "[2] Show out Huffman hash map" << endl;
        cout << "[3] Encode element" << endl;
        cout << "[4] Decode element" << endl;
        cout << "[5] Exit" << endl << endl;

        cout << "Plz choose:";
        cin >> choose;

        switch(choose)
        {
            case 1:
                huffman.getMap();
                break;
            case 2:
                huffman.showMap();
                break;
            case 3:
                huffman.encodeElement();
                break;
            case 4:
                huffman.decodeElement();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout << "Plz consider another choose!" << endl;
                break;
        }
    }


    return 0;
}