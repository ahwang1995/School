import junit.framework.* ;
import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda
Date: 6/4/14*/
public class UnicalcTester extends TestCase {

	private Unicalc asdf;
	private Unicalc qwer;
	private AST astobj;
	private AST astobj2;
	
	public UnicalcTester()
	{
		super();
	}
	
	/** setUp creates new Unicalc objects*/
	public void setUp()
	{
		asdf = new Unicalc();
		qwer = new Unicalc();
	}
	/**
	 * Tests the S method
	 */
	public void testS()
	{
		asdf.tokenize("def asdf");
		astobj = asdf.S();
		assertEquals("Define(asdf,Value(1.0 asdf))",astobj.toString());
	}
	/**
	 * Tests the L method
	 */
	public void testL()
	{
		asdf.tokenize("# 20km");
		astobj = asdf.L();
		assertEquals("Normalize(Product(Value(20.0),Value(1.0 km)))",astobj.toString());
	}
	/**
	 * Tests the E method
	 */
	public void testE()
	{
		asdf.tokenize("4m - 3m");
		astobj = asdf.E();
		assertEquals("Difference(Product(Value(4.0)"
				+ ",Value(1.0 m)),Product(Value(3.0),Value(1.0 m)))",astobj.toString());
		
		qwer.tokenize("4m + 3m");
		astobj2 = qwer.E();
		assertEquals("Sum(Product(Value(4.0),Value(1.0 m))"
				+ ",Product(Value(3.0),Value(1.0 m)))",astobj2.toString());
	}
	/**
	 * Tests the P method
	 */
	public void testP()
	{
		asdf.tokenize("6m*5m");
		astobj = asdf.P();
		assertEquals("Product(Product(Value(6.0),Value(1.0 m))"
				+ ",Product(Value(5.0),Value(1.0 m)))",astobj.toString());
		qwer.tokenize("10m/2");
		astobj2 = qwer.P();
		assertEquals("Quotient(Product(Value(10.0),Value(1.0 m))"
				+ ",Value(2.0))",astobj2.toString());
	}
	/**
	 * Tests the K method
	 */
	public void testK()
	{
		asdf.tokenize("-5m + 7m");
		astobj = asdf.K();
		assertEquals("Negation(Product(Value(5.0),Value(1.0 m)))",astobj.toString());
	}
	
	/**
	 * Tests the Q method
	 */
	public void testQ()
	{
		asdf.tokenize("2m 4m");
		astobj = asdf.Q();
		assertEquals("Product(Value(2.0),Product(Value(1.0 m)"
				+ ",Product(Value(4.0),Value(1.0 m))))",astobj.toString());
	}
	/**
	 * Tests the R method
	 */
	public void testR()
	{
		asdf.tokenize("m^2");
		astobj = asdf.R();
		assertEquals("Power(Value(1.0 m),2)",astobj.toString());
	}
	/**
	 * Tests the V method
	 */
	public void testV()
	{
		asdf.tokenize("5m + 1m");
		astobj = asdf.V();
		assertEquals("Value(5.0)",astobj.toString());
	}
}
