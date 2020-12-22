#include "Huffman.h"

//int index = 0;

// @brief 排序函数
bool sortByWeight(HuffNode * first, HuffNode * second)
{
    return first->weight < second->weight;
}

// @brief 构造函数
Huffman::Huffman()
{
    huffHeadPtr = nullptr; // 头节点指向空
//    index = 0;
}

// @brief 析构函数
Huffman::~Huffman()
{
    // TODO:递归删除哈弗曼树
    delete huffHeadPtr;    // 删除头节点
    encode = "";
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
//    char flag;
    cout << huffman_map.size() << endl;

    for(iter = huffman_map.begin(); iter != huffman_map.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << endl;
//    flag = getchar();
}

// @brief 编码
void Huffman::encodeElement()
{
    char flag;
    char input;

    // input elements
    while(true)
    {
        cin >> input;
        huffdata.push_back(input);

        if((flag = getchar()) == '\n')
            break;
    }

    // 创建初始化容器
    for(iter = huffman_map.begin(); iter != huffman_map.end(); iter++)
    {
        HuffNode * temp = new HuffNode;

        temp->data = iter->first;
        temp->weight = iter->second;
        temp->left = nullptr;
        temp->right = nullptr;

        huffnodes.push_back(temp);
    }


    createTree();   // 构造huffman树

    // 使用层次遍历 构造每一个节点Huffman编码
    if(huffHeadPtr == nullptr)
        return;

    HuffNode * headTemp = huffHeadPtr;
    queue<HuffNode *> huffnodes_qe;
    huffnodes_qe.push(headTemp);

    while(huffnodes_qe.size() > 0)
    {
        headTemp = huffnodes_qe.front();
        huffnodes_qe.pop();

        if(headTemp->left)
        {
            huffnodes_qe.push(headTemp->left);
            headTemp->left->huff_code = headTemp->huff_code + "0";
        }
        if(headTemp->right)
        {
            huffnodes_qe.push(headTemp->right);
            headTemp->right->huff_code = headTemp->huff_code + "1";
        }
    }

    preOrder(huffHeadPtr);    // 使用遍历来验证Huffman

    cout << "huffdata.size() " << huffdata.size() << endl;

    for(auto data : huffdata)
    {
        setEncode(huffHeadPtr, data);
    }

    cout << "编码后的信息:" << encode << endl;
}

// @brief 解码
void Huffman::decodeElement()
{
    // TODO: 完善解码程序
    cin >> encode;

    cout << "encode.size() " << encode.size() << endl;

//    setDecode(huffHeadPtr, encode);
    int index = 0;
    HuffNode * temp = huffHeadPtr;
    while(index < encode.size())
    {
        if(encode.at(index) == '0')
        {
            temp = temp->left;
            index++;
        }
        else if(encode.at(index) == '1')
        {
            temp = temp->right;
            index++;
        }

        if(temp->left == nullptr && temp->right == nullptr)
        {
            decode += temp->data;
            temp = huffHeadPtr;
            //            continue;
        }
    }

//    cout << decode << endl;

    cout << "decode" << decode << endl;
}

// @brief 设置编码
void Huffman::setEncode(HuffNode * head, char data)
{
    if(head)
    {
        if(head->data == data)
            encode += head->huff_code;
        setEncode(head->left, data);
        setEncode(head->right, data);
    }
}

// @brief 设置解码
//void Huffman::setDecode(HuffNode * head, string encode)
//{
//    // TODO: 补全函数
//
//    if(head)
//    {
//        cout << "index" << index << endl;
//        if(index > encode.size())
//            return;
//
//        if(head->left == nullptr && head->right == nullptr)
//        {
//            decode += head->data;
//            head = huffHeadPtr;
//        }
//
//        if(encode.at(index) == '0')
//        {
//            index++;
//            setDecode(head->left, encode);
//        }
//
//        if(encode.at(index) == '1')
//        {
//            index++;
//            setDecode(head->right, encode);
//        }
//    }
//}

// @brief 创建Huffman树
void Huffman::createTree()
{
    while(huffnodes.size() > 0)
    {
        // 按照weight从小到大进行排序
        sort(huffnodes.begin(), huffnodes.end(), sortByWeight);

        // 取出前两个节点
        if(huffnodes.size() == 1)
        {
            huffHeadPtr = huffnodes.at(0);
            huffnodes.erase(huffnodes.begin()); // 删除
        }
        else
        {
            // 取出前两个
            HuffNode * node_1 = huffnodes.at(0);
            HuffNode * node_2 = huffnodes.at(1);
            // 删除
            huffnodes.erase(huffnodes.begin());
            huffnodes.erase(huffnodes.begin());
            // 生成新的节点
            HuffNode * temp = new HuffNode;
            temp->weight = node_1->weight + node_2->weight;

            (node_1->weight < node_2->weight) ?
            (temp->left = node_1, temp->right = node_2) :
            (temp->left = node_2, temp->right = node_1);

            huffnodes.push_back(temp);
        }
    }
}

// @brief 使用先序遍历出叶子节点的Huffman值
void Huffman::preOrder(HuffNode *head)
{
    if(head)
    {
        if(head->left == nullptr && head->right == nullptr)
        {
            cout << head->data << " " << head->huff_code << endl;
        }
        preOrder(head->left);
        preOrder(head->right);
    }
}

//　＠brief 使用中序遍历出叶子节点的Huffman值
void Huffman::inOrder(HuffNode *head)
{
    if(head)
    {
        preOrder(head->left);
        if(head->left == nullptr && head->right == nullptr)
        {
            cout << head->data << " " << head->huff_code << endl;
        }
        preOrder(head->right);
    }
}

// @brief 使用后序遍历出叶子节点的Huffman值
void Huffman::postOrder(HuffNode *head)
{
    if(head)
    {
        preOrder(head->left);
        preOrder(head->right);
        if(head->left == nullptr && head->right == nullptr)
        {
            cout << head->data << " " << head->huff_code << endl;
        }
    }
}