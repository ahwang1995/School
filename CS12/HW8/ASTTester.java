import junit.framework.* ;
import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda
Date: 6/4/14*/
public class ASTTester extends TestCase{

	private Quantity q1;
	private Quantity q2;
	private Quantity q3;
	private Quantity q4;
	private Quantity q5;
	private Value v1;
	private Value v2;
	private Value v3;
	private Value v4;
	private Value v5;
	private Map<String,Quantity> db;
	private List<String> emp;
	public ASTTester()
	{
		super();
	}
	/** setUp initialized the database, and empty arraylist and
	 * a variety of values using quantities
	 */
	public void setUp()
	{
		db = QuantityDB.getDB();
		emp = new ArrayList<String>();
		q1 = new Quantity(1.0,Arrays.asList("m"),emp);
		q2 = new Quantity(2.0,Arrays.asList("m"),emp);
		q3 = new Quantity(3.0,Arrays.asList("m"),emp);
		q4 = new Quantity(2.0,Arrays.asList("s"),emp);
		q5 = new Quantity(4.0,Arrays.asList("s"),emp);
		v1 = new Value(q1);
		v2 = new Value(q2);
		v3 = new Value(q3);
		v4 = new Value(q4);
		v5 = new Value(q5);
	}
	
	/**
	 * Tests the Product method
	 */
	public void testProduct()
	{
		Product p = new Product(v2,v4);
		assertEquals("4.0 m s",p.eval(db).toString());
	}
	/**
	 * Tests the Quotient method
	 */
	public void testQuotient()
	{
		Quotient q = new Quotient(v5,v4);
		assertEquals("2.0",q.eval(db).toString());
	}
	/**
	 * Tests the Sum method
	 */
	public void testSum()
	{
		Sum s = new Sum(v1,v2);
		assertEquals("3.0 m",s.eval(db).toString());
	}
	/**
	 * Tests the Difference method
	 */
	public void testDifference()
	{
		Difference d = new Difference(v2,v1);
		assertEquals("1.0 m",d.eval(db).toString());
	}
	/**
	 * Tests the Power Method
	 */
	public void testPower()
	{
		Power pow = new Power(v2,2);
		assertEquals("4.0 m^2",pow.eval(db).toString());
	}
	/**
	 * Tests the Negation method
	 */
	public void testNegation()
	{
		Negation n = new Negation(v2);
		assertEquals("-2.0 m",n.eval(db).toString());
	}
	/** Tests the normalize method
	 * 
	 */
	public void testNormalize()
	{
		Quantity newquant = new Quantity(15,Arrays.asList("minute"),emp);
		Normalize norm = new Normalize(v4);
		assertEquals("2.0 second",norm.eval(db).toString());
	}
	/**
	 * Tests the Define method
	 */
	public void testDefine()
	{
		Define def = new Define("Hello",v5);
		assertEquals("4.0 s",def.eval(db).toString());
	}
	/**
	 * Tests the Value method
	 */
	public void testValue()
	{
		assertEquals("2.0 m",v2.eval(db).toString());
	}
}
