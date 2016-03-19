class shape{
   protected: 
      int width;
      int height;
   public:
      shape(int a, int b): width(a),height(b){}
      virtual int area(void) = 0;
};
class Rectangle:public shape{
   public:
      Rectangle(int a, int b): shape(a,b){}
      int area(){
         return width*height;
      }
};
