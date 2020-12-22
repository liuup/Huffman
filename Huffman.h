#ifndef MAIN_HUFFMAN_H
#define MAIN_HUFFMAN_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct HuffNode
{
    char data;  // 信息
    int weight; // 权值
//    char huffman_code[512];
    string huff_code;
    HuffNode * left;    // 左节点
    HuffNode * right;   // 右节点
};

class Huffman
{
public:
    Huffman();
    ~Huffman();

    void getMap();  // 输入Huffman映射表
    void showMap(); // 显示Huffman映射表

    void encodeElement();  // 编码
    void decodeElement();  // 解码

    void setEncode(HuffNode * head, char data); // 输出编码后的信息
    void setDecode(); // 输出解码后的信息

    void createTree();  // 创建Huffman

    void preOrder(HuffNode * head);
    void inOrder(HuffNode * head);
    void postOrder(HuffNode * head);

private:
    map<char, int> huffman_map;     // Huffman映射表
    map<char, int>::iterator iter;  // Huffman映射表遍历

    vector<char> huffdata;  //  输入的元素
    vector<HuffNode *> huffnodes; // 输入的元素

    string encode;  // 编码后的信息
    string decode;  // 解码后的信息

    HuffNode * huffHeadPtr;          // Huffman头节点




};


#endif //MAIN_HUFFMAN_H
