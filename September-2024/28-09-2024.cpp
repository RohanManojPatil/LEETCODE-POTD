class Node
{
   public:
        int data;
        Node* left;
        Node* right;
        
        Node(int x)
        {
            data = x;
            left = right = NULL;
        }
};

class MyCircularDeque {
public:
    int curr_size, total_size;
    Node* head, *tail;
    MyCircularDeque(int k) {
        curr_size = 0;
        total_size = k;
        head = tail = NULL;
    }
    
    bool insertFront(int value) {
        
      if(curr_size == total_size)
      {
          return false;
      }
      
      Node *node = new Node(value);
      
      if(head == NULL)
      {
          node->right = node;
          node->left = node;
          head = tail = node;
      }
      else
      {
          node->right = head;
          head->left = node;
          node->left = tail;
          head = node;
          tail->right = head;
      }
      curr_size++;

      return true;
    }
    
    bool insertLast(int value) {
      if(curr_size == total_size)
      {
          return false;
      }
      
      Node *node = new Node(value);
      if(head == NULL)
      {
          node->right = node;
          node->left = node;
          head = tail = node;
      }
      else
      {
          tail->right = node;
          node->left = tail;
          node->right = head;
          tail = node;
          head->left = node;
      }	
      
      curr_size++;
      return true;
    }
    
    bool deleteFront() {
      if(curr_size == 0)
      {
         return false;
      }
      
      head = head->right;
      head->left = tail;
      tail->right = head;
      curr_size--;
      
      if(curr_size == 0)
      {
            head = tail = NULL;
      }

      return true;
    }
    
    bool deleteLast() {
      if(curr_size == 0)
      {
         return false;
      }
      
      tail = tail->left;
      tail->right = head;
      head->left = tail;
      curr_size--;

      if(curr_size == 0)
      {
         head = tail = NULL;
      }

      return true;
    }
    
    int getFront() {
        if(head != NULL)
        {
            return head->data;
        }

        return -1;
    }
    
    int getRear() {
        if(tail != NULL)
        {
            return tail->data;
        }

        return -1;
    }
    
    bool isEmpty() {
        return curr_size == 0;
    }
    
    bool isFull() {
        return curr_size == total_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */