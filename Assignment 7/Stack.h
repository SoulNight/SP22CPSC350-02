
/* *********************************************************************************
 *  Template Base Class - Stack
 * ---------------------------------------------------------------------------------
 *  Stack.h is the blueprint for the Stack datatype.
 * **********************************************************************************/
template <typename E>
class Stack{
public:
  Stack(){};
  virtual ~Stack(){};
  // Re-initializes the stack
  virtual void clear()=0;

  // push an element onto the top of the stack
  virtual void push(const E& item)=0;

  // remove an element
  virtual E pop()=0;

  // return the number of elements in the stack
  virtual int length()=0;
};
