#include "Huffman.h"

// @brief 构造函数
Huffman::Huffman()
{
    huffHeadPtr = nullptr; // 头节点指向空
}


// @brief 析构函数
Huffman::~Huffman()
{
    delete huffHeadPtr;    // 删除头节点
}

// @brief 输入Huffman映射表
void Huffman::getMap()
{
    char flag;  // 判断回车标志
    char input_char;    // 输入的字符
    int input_weight;  // 输入的权重

    while(true)
    {
        cin >> input_char;
        huffman_map.insert(pair<char, int>(input_char, -1));    // 插入字符

        if((flag = getchar()) == '\n')
            break;
    }

    for(iter = huffman_map.begin(); iter != huffman_map.end(); iter++)
    {
        cin >> input_weight;
        iter->second = input_weight;

        flag = getchar();   // 吸收逗号
    }
}

// @brief 打印Huffman映射表
void Huffman::showMap()
{
    for(iter = huffman_map.begin(); iter != huffman_map.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
}

// @brief
void Huffman::encodeElement()
{

}

// @brief
void Huffman::decodeElement()
{


}

// @brief 创建Huffman树
void Huffman::createTree()
{

}