void creat(BiTree &Tree) {
    char ch;
    scanf(" %c", &ch); // 读取字符，注意前面有个空格用来过滤掉空白符
    if (ch == '#') {
        Tree = NULL; // 如果当前字符为'#'，则当前子树为空，即无左子或右子
    } else {
        Tree = (BiTree)malloc(len); // 分配内存
        Tree->data = ch; // 将读取的字符赋值给节点的数据域
        creat(Tree->lchild); // 递归构造左子树
        creat(Tree->rchild); // 递归构造右子树
    }
}

int countleaf(BiTree Tree) {
    if (!Tree) {
        return 0; // 如果是空树或者达到叶子节点的子节点，返回0
    }
    if (!Tree->lchild && !Tree->rchild) {
        return 1; // 如果左右孩子都为空，则为叶子节点，返回1
    } else {
        return countleaf(Tree->lchild) + countleaf(Tree->rchild); // 否则，递归统计左右子树的叶子节点数并返回总和
    }
}