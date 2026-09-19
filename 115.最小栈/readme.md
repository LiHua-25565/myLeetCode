使用一个辅助栈记录当前最小值
看评论发现一个有意思的题解可以不使用辅助栈，实时记录minval，只用一个栈记录diff(value-minval),后续还原的时候,if(diff>=0) val = minval+diff, else if(diff<0) minval = val；