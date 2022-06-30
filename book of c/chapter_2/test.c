
int zbytel(unsigned x) {
   unsigned y;
   int n;
                          // Original byte: 00 80 other
   y = (x & 0x7F7F7F7F)+ 0x7F7F7F7F;     // 7F 7F 1xxxxxxx
   y = ~(y & x + 0x7F7F7F7F);            // 80 00 00000000
   return n;                     // has no 0-byte.
}
int main(){


};
