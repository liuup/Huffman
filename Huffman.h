#ifndef MAIN_HUFFMAN_H
#define MAIN_HUFFMAN_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct HuffNode
{
    char data;  // 信息
    int weight; // 权值
    string huffman_code;  // Huffman编码值
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

    void createTree();  // 创建Huffman

    void preOrder(HuffNode * head);    // 前序遍历
    void inOrder(HuffNode * head);     // 中序遍历
    void postOrder(HuffNode * head);   // 后序遍历

private:
    map<char, int> huffman_map;     // Huffman映射表
    map<char, int>::iterator iter;  // Huffman映射表遍历

    vector<HuffNode *> huffnodes; // 输入的元素

    HuffNode * huffHeadPtr;          // Huffman头节点

};

#endif //MAIN_HUFFMAN_H