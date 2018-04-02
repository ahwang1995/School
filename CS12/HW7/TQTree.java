/**
 * TQTree.java
 * A Java class that supports a Binary Tree that plays the game of twenty questions
 * 
 * @author Christine Alvarado
 * @version 2.0
 * @date May 11, 2014
 */

import java.io.*;
import java.util.*;
import java.text.ParseException;
import java.util.LinkedList;

/*CSE 12 Homework 7
Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda
Section: B00
Date: 5/21/14*/
public class TQTree {
  private TQNode root;
  
  /** Inner class that supports a node for a twenty questions tree.
    * You should not need to change this class. */
  class TQNode {
    /*  You SHOULD NOT add any instance variables to this class */
    TQNode yesChild;  // The node's right child
    TQNode noChild;   // The node's left child
    String data;      // A question (for non-leaf nodes) 
                      // or an item (for leaf nodes)
    
    int idx;        // index used for printing
    
    /** Make a new TWNode 
      * @param data The question or answer to store in the node. 
      */
    public TQNode( String data )
    {
      this.data = data;
    }    
    
    /** Setter for the noChild 
      * @param noChild The new left (no) child
      */
    public void setNoChild( TQNode noChild )
    {
      this.noChild = noChild;
    }
    
    
    /** Setter for the yesChild 
      * @param yesChild The new right (yes) child
      */
    public void setYesChild( TQNode yesChild )
    {
      this.yesChild = yesChild;
    }
    
        
    /** Getter for the yesChild 
      * @return The node's yes (right) child
      */
    public TQNode getYesChild()
    {
      return this.yesChild;
    }

    /** Getter for the noChild 
      * @return The node's no (left) child
      */
    public TQNode getNoChild()
    {
      return this.noChild;
    }
    
    /** Getter for the data
      * @return The data stored in this node
      */
    public String getData()
    {
      return this.data;
    }
    
    /** Setter for the index
      * @param idx index of this for printing 
      */
    public void setIndex(int idx) {
      this.idx = idx;
    }
    
    /** get the index
      * @return idx index of this for printing 
      */
    public int getIndex() {
      return this.idx;
    }
  }  // End TQNode

  
  /** Builds a starter TQ tree with 1 question and 2 answers */
  public TQTree()
  {
	  this.root = new TQNode("Is it bigger than a breadbox");
	  TQNode noNode = new TQNode("spam");
	  root.setNoChild(noNode);
	  TQNode yesNode = new TQNode("a computer scientist");
	  root.setYesChild(yesNode);
	  
    // TODO: Complete this method.  See the HW writeup for details 
    // about what the initial question and answers should be.
  }
  
  /** Builds a new TQTree by reading from a file 
    * @param filename The file containing the tree
 * @throws ParseException 
    * @throws FileNotFoundException if the file cannot be found or read.
    * */
  public TQTree( String filename ) throws ParseException
  {
    File f = new File( filename );
    LineNumberReader reader;
    try {
      reader = new LineNumberReader( new FileReader( f ));
    } catch ( FileNotFoundException e ) {
      System.err.println( "Error opening file " + filename );
      System.err.println( "Building default Question Tree." );
      
     // TODO: Add code to build the default tree here
      TQTree noargtree = new TQTree();
      return;
    }
    
    // TODO: Add code to read in the tree from a file here.  
    // Note: You will likely find the private method buidSubtree helpful here.  
    // Also, consider making your own private helper method to do most of the work here.
    try
    {
    	root = buildSubtree(reader);
    }
    catch(ParseException e)
    {
    	System.err.println("Error" + filename + "at" + reader.getLineNumber());
    }
    try {
      reader.close();
    } catch ( IOException e ) {
      System.err.println( "An error occured while closing file " + filename );
    }
    
  }
  
  /** Play one round of the game of Twenty Questions using this game tree 
    * Augments the tree if the computer does not guess the right answer
    */ 
  public void play() throws NullPointerException
  {
	  TQNode temp = root;
	  if ( temp.data == null ) {
	      // We should never be calling this method if we don't have any more input
	      throw new NullPointerException();
	    }
	  Scanner scan;
	  System.out.println(temp.getData());
	  while(temp.getYesChild() != null && temp.getNoChild() != null)
	  {
		  scan = new Scanner(System.in);
		  String yesorno = scan.next();
		  yesorno.replaceAll("\\s+","");
		  if(yesorno.equalsIgnoreCase("yes") || yesorno.equalsIgnoreCase("y"))
		  {
			  temp = temp.getYesChild();
		  }
		  if(yesorno.equalsIgnoreCase("no") || yesorno.equalsIgnoreCase("no"))
		  {
			  temp = temp.getNoChild();
		  }
		  System.out.println(temp.getData());
	  }
	  System.out.println("Is " + temp.getData() + " the object you were thinking of?");
	  Scanner answer = new Scanner(System.in);
	  String iswon = answer.next();
	  if(iswon.equalsIgnoreCase("yes") || iswon.equalsIgnoreCase("y"))
	  {
		  System.out.println("The game is won!");
	  }
	  if(iswon.equalsIgnoreCase("no") || iswon.equalsIgnoreCase("n"))
	  {
		  String theobject = temp.getData();
		  TQNode theobjectnode = new TQNode(theobject);
		  System.out.println("Ok, what was it?");
		  Scanner newobject = new Scanner(System.in);
		  String thenewobject = newobject.next();
		  TQNode thenewobjectnode = new TQNode(thenewobject);
		  System.out.println("What is a question that would distinguish " + thenewobject +
				  " from " + theobject);
		  Scanner question = new Scanner(System.in);
		  String thequestion = question.nextLine();
		  System.out.println("Would the answer to the question for a " + 
		  thenewobject + " be yes or no?");
		  Scanner objectanswer = new Scanner(System.in);
		  String theobjectanswer = objectanswer.next();
		  temp.data = thequestion;
		  if(theobjectanswer.equalsIgnoreCase("yes") || theobjectanswer.equalsIgnoreCase("y"))
		  {
			  temp.setYesChild(thenewobjectnode);
			  temp.setNoChild(theobjectnode);
		  }
		  if(theobjectanswer.equalsIgnoreCase("no") || theobjectanswer.equalsIgnoreCase("n"))
		  {
			  temp.setYesChild(theobjectnode);
			  temp.setNoChild(thenewobjectnode);
		  }
		  
	  }
	  
  }
  
  /** Save this Twenty Questions tree to the file with the given name
    * @param filename The name of the file to save to
    * @throws FileNotFoundException If the file cannot be used to save the tree
    */
  public void save( String filename ) throws FileNotFoundException
  {
	  File file = new File(filename);
	  PrintWriter printer = null;
	  try
	  {
		  printer = new PrintWriter(file);
	  }
	  catch(FileNotFoundException e)
	  {
		  
	  }
	  printsave(printer, root);
	  printer.close();
  }
  
  
  /** Print a level-order traversal of the tree to standard out (System.out)
    * */ 
  public void print()
  {
	  BFS(root);
  }
 
  
  // PRIVATE HELPER METHODS
// You will likely want to add a few more private helper methods here.    

  /**
   * Helper method to copy the tree into a file, used by the save method
   */
  private void printsave(PrintWriter printer, TQNode node)
  {
	  TQNode tempnode = node;
	  if(tempnode == null)
	  {
		  return;
	  }
	  if(tempnode.getNoChild() == null && tempnode.getYesChild() == null)
	  {
		  printer.println("A:" + tempnode.getData());
	  }
	  else
	  {
		  printer.println("Q:" + tempnode.getData());
	  }
	  if(tempnode.getNoChild() != null)
	  {
		  printsave(printer, tempnode.getNoChild());
	  }
	  if(tempnode.getYesChild() != null)
	  {
		  printsave(printer, tempnode.getYesChild());
	  }
  }
  
  /**
   * Helper method to print the tree using a Breath First search
   */
  private void BFS(TQNode rootnode)
  {
	  LinkedList<TQNode> q = new LinkedList<TQNode>();
	  q.add(rootnode);
	  rootnode.idx = 0;
	  int index = 1;
	  while(!q.isEmpty())
	  {
		  TQNode current = q.remove();
		  if(current.getNoChild() != null)
		  {
			  current.noChild.idx = index;
			  q.add(current.getNoChild());
			  index++;
		  }
		  if(current.getYesChild() !=null)
		  {
			  current.yesChild.idx = index;
			  q.add(current.getYesChild());
			  index++;
		  }
		  try
		  {
		  System.out.println(current.idx + ":    " + "'" + current.getData()
				  + "'   " + "no:(" + current.noChild.idx + ")   yes:(" +
				  current.yesChild.idx + ")");
		  }
		  catch(NullPointerException e)
		  {
			  System.out.println(current.idx + ":    " + "'" + current.getData()
					  + "'   " + "no:(" + "null" + ")   yes:(" +
					  "null" + ")");
		  }
	  }
  }
  /** Recursive method to build a TQTree by reading from a file.
    * @param reader A LineNumberReader that reads from the file
    * @return The TQNode at the root of the created tree
    * @throws ParseException If the file format is incorrect
    */
  private TQNode buildSubtree( LineNumberReader reader ) throws ParseException 
  {
    
    String line;
    try {
      line = reader.readLine();
    }
    catch ( IOException e ) {
      throw new ParseException( "Error reading tree from file: " + e.getMessage(),
                               reader.getLineNumber() );
    }
    
    if ( line == null ) {
      // We should never be calling this method if we don't have any more input
      throw new ParseException( "End of file reached unexpectedly", reader.getLineNumber() );
    }
    
    String[] lineSplit = line.split( ":", 2 );
    String qOrA = lineSplit[0];
    String data = lineSplit[1];
    
    TQNode subRoot = new TQNode( data );
    if ( qOrA.equals( "Q" ) ) {
      subRoot.setNoChild( buildSubtree( reader ) );
      subRoot.setYesChild( buildSubtree( reader ) );
    }    
    return subRoot;
  }


  
}
