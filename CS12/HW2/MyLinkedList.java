/** Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda*/

import java.util.*;
public class MyLinkedList<E> extends AbstractList<E> {

	private int nelems;
	private Node head;
	private Node tail;
	

	protected class Node {
		E data;
		Node next;
		Node prev;

		/** Constructor to create singleton Node */
		public Node(E element)
		{
			data = element;
			next = null;
			prev = null;
			
		}
		/** Constructor to create singleton link it between previous and next 
	 	*   @param element Element to add, can be null
	 	*   @param prevNode predecessor Node, can be null
	 	*   @param nextNode successor Node, can be null 
	 	*/
			public Node(E element, Node prevNode, Node nextNode)
		{
				data = element;
				next = nextNode;
				prev = prevNode;
		}
		/** Remove this node from the link. Update previous and next nodes */
		public void remove()
		{
			data = null;
			this.prev.next = this.next;
			this.next.prev = this.prev;
			this.prev = null;
			this.next = null;
			if(nelems>0)
			{
				nelems--;
			}
		}
		/** Set the previous node in the list
		 *  @param p new previous node
		 */
		public void setPrev(Node p)
		{
			this.prev = p;
		}
		/** Set the next node in the list
		 *  @param n new next node
		 */
		public void setNext(Node n)
		{
			this.next = n;
		}
		   
		/** Set the element 
		 *  @param e new element 
		 */
		public void setElement(E e)
		{
			data = e;
		}
		/** Accessor to get the next Node in the list */
		public Node getNext()
		{
            return (Node)this.next;
		}
		/** Accessor to get the prev Node in the list */
		public Node getPrev()
		{
            return (Node) this.prev;
		} 
		/** Accessor to get the Nodes Element */
		public E getElement()
		{
            return (E) this.data;
		} 
	}

    /** ListIterator implementation */ 
	protected class MyListIterator implements ListIterator<E> {

        private boolean forward;
        private boolean canRemove;
        private Node left,right; // Cursor sits between these two nodes
        private int idx;        // Tracks current position. what next() would
                                // return 
        public MyListIterator()
        {
        	head = new Node(null);
        	tail = new Node(null);
        	head.setNext(tail);
        	tail.setPrev(head);
        	left = head;
        	right = head.next;
        	idx = 0;
        }
		@Override
		public void add(E e) throws  NullPointerException
		{
			Node newNode = new Node(e,left,right);
			left.setNext(newNode);
			right.setPrev(newNode);
			nelems++;
		}
		@Override
		public boolean hasNext() throws NoSuchElementException
		{
			boolean hasNext = false;
			if(right.getNext() != null)
			{
				hasNext = true;
			}
            return hasNext;
		}

		@Override
		public boolean hasPrevious() throws NoSuchElementException
		{
			boolean hasPrevious = false;
			if(left.getPrev() != null)
			{
				hasPrevious = true;
			}
            return hasPrevious;
		}
		@Override
		public E next() throws NoSuchElementException
		{
			if(hasNext())
			{
				forward = true;
				if(right.getNext() != null)
				{
					canRemove = true;
				}
				if(right.getNext() == null)
				{
					canRemove = false;
				}
				left = right;
				right = right.next;
				idx++;
			}
            return (E) left.getElement();
		}
		@Override
		public int nextIndex()
		{
            return idx + 1;
		}
		@Override
		public E previous() throws NoSuchElementException
		{
			if(hasPrevious())
			{
				forward = false;
				if(left.getPrev() != null)
				{
					canRemove = true;
				}
				if(left.getPrev() == null)
				{
					canRemove = false;
				}
				right = left;
				left = left.prev;
				idx--;
			}
			
            return (E) left.getElement();
		}

		@Override
		public int previousIndex()
		{
            return idx -1;
		}
		@Override
		public void remove() throws IllegalStateException
		{
			if(canRemove && forward)
			{
				left.remove();
				left = right.getPrev();
				idx --;
				nelems--;
			}
			if(canRemove && !forward)
			{
				right.remove();
				right = left.getNext();
				idx--;
				nelems--;
			}
		}
		@Override
		public void set(E e) throws NullPointerException
		{
			left.data = e;
		}

	}


	//  Implementation of the MyLinkedList Class


    /** Only 0-argument constructor is define */
    public MyLinkedList()
    {
    	head = new Node(null);
    	tail = new Node(null);
    	head.setNext(tail);
    	tail.setPrev(head);
    }
	@Override
	public int size()
	{
	    // need to implement the size method
	    return nelems;
	}

	@Override
	public E get(int index) throws IndexOutOfBoundsException
	{
		Node a = head;
		if(index < nelems && index >= 0)
		{
	    	for(int i = 0; i<=index; i++)
	    	{
	    		a = a.getNext();
	    	}
		}
        return (E) a.getElement();
	}

	@Override
    /** Add an element to the list 
     * @param index  where in the list to add
     * @param data data to add
     * @throws IndexOutOfBoundsException
     * @throws NullPointerException
     */ 
	public void add(int index, E data) 
        throws IndexOutOfBoundsException,NullPointerException
	{
		Node a = head;
		Node b = null;
		if(index < nelems)
		{
			for(int i = 0; i<index; i++)
			{
				a = a.getNext();
				b = a.getPrev();
			}
			Node newNode = new Node(data, b, a);
			b.setNext(newNode);
			a.setPrev(newNode);
			nelems++;
		}
	}
    /** Add an element to the end of the list 
     * @param data data to add
     * @throws NullPointerException
     */ 
    public boolean add(E data) throws NullPointerException
    {
    	Node a = tail;
    	Node newNode = new Node(data);
    	newNode.setNext(a);
    	newNode.setPrev(a.getPrev());
    	a.setPrev(newNode);
    	nelems ++;
        return true;
    }

    /** Set the element at an index in the list 
     * @param index  where in the list to add
     * @param data data to add
     * @return element data added
     * @throws IndexOutOfBoundsException
     * @throws NullPointerException
     */ 
	public E set(int index, E data) 
        throws IndexOutOfBoundsException,NullPointerException
	{
		Node a = head;
		for(int i = 0; i<index; i++)
		{
			a = a.getNext();
		}
		a.setElement(data);
        return (E) a.data; 
	}

    /** Remove the element at an index in the list 
     * @param index  where in the list to add
     * @return element the data found
     * @throws IndexOutOfBoundsException
     */ 
    public E remove(int index) throws IndexOutOfBoundsException
    {
    	E removedData = null;
    	Node a = head;
    	if(index < nelems)
    	{
    		for(int i = 0; i<index; i++)
    		{
    			a = a.getNext();
    		}
    		removedData = a.data;
    		a.remove();
    		nelems--;
    	}
        return removedData;
    }

    /** Clear the linked list */
    public void clear()
    {
    	Node a = head;
    	while(a.equals(head))
    	{
    		a = a.getNext();
    	}
    	if(a != tail && a != head)
    	{
    		a.remove();
    		a = head;
    	}
    	nelems = 0;
    }

    /** Determine if the list empty 
     *  @return true if empty, false otherwise */
    public boolean isEmpty()
    {
    	if(nelems != 0)
    	{
    		return false;
    	}
        return true;
    }

	public Iterator<E> QQQiterator()
	{
	return new MyListIterator();
	}
	public ListIterator<E> QQQlistIterator()
	{
	return new MyListIterator();
	}

    // Helper method to get the Node at the Nth index
    private Node getNth(int index) 
    {
    	Node a = head;
    	for(int i = 0; i<index; i++)
    	{
    		a = a.getNext();
    	}
        return (Node) a;
    }

     
                

/*  UNCOMMENT the following when you believe your MyListIterator class is
	functioning correctly*/
	public Iterator<E> iterator()
	{
	return new MyListIterator();
	}
	public ListIterator<E> listIterator()
	{
	return new MyListIterator();
	}

}

// VIM: set the tabstop and shiftwidth to 4 
// vim:tw=78:ts=4:et:sw=4

