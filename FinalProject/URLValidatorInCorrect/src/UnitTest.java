import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class UnitTest {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	
	//test the regular testing scheme passing 
	@Test
	public void testIsValiddefaultSchemePassing() {
		
		UrlValidator validator = new UrlValidator();
		assertTrue(validator.isValid("http://google.com"));
		assertTrue(validator.isValid("https://google.com/"));
		assertTrue(validator.isValid("https://google.com/mail"));
		assertTrue(validator.isValid("http://www.google.com"));	
		assertTrue(validator.isValid("https://8.8.8.8"));
		assertTrue(validator.isValid("ftp://google.com"));
		assertTrue(validator.isValid("http://www.google.uk"));
	}
	//test invalid regular testing default scheme failing 
	@Test
	public void testIsValidDefualtSchemeFailing() {
		UrlValidator validator = new UrlValidator();
		assertFalse(validator.isValid("https://localhost"));
		assertFalse(validator.isValid("http://localhost/"));
		assertFalse(validator.isValid("localhost:80"));	
		assertFalse(validator.isValid("www.google.com"));
		assertFalse(validator.isValid("google.com"));
		assertFalse(validator.isValid("google.uk"));
		assertFalse(validator.isValid("tyr.google.uk"));
	}
	//Test schemes will pass 
	@Test 
	public void testIsValidSchemesTest() {
		
		String[] schemes = {"file", "userOwScheme"};
        UrlValidator validator = new UrlValidator(schemes);
		assertTrue(validator.isValid("file:/class"));
		assertTrue(validator.isValid("userOwScheme://cs362.com"));
	}
	//Test schemes will pass 
	@Test 
	public void testIsValidQueryStrings() {
			
	    UrlValidator validator = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
		assertTrue(validator.isValid("https://www.google.com/serch?name=stephen"));
		assertTrue(validator.isValid("https://www.google.com?name=stephen"));
	}
	//test should not allow other schemes. Only user designated 
	@Test
	public void testValidSchemeFail() {
		
		String[] schemes = {"file", "userOwScheme"};
        UrlValidator validator = new UrlValidator(schemes);
		assertFalse(validator.isValid("f:/class"));
		assertFalse(validator.isValid("userOwn:/class"));
		assertFalse(validator.isValid("http:/class"));
		assertFalse(validator.isValid("https:/class"));
		assertFalse(validator.isValid("ftp:/class"));
    }
	//test to make sure user can declare all schemes are valid 
	@Test
	public void testValidAllowAllSchemes() {
		long options = UrlValidator.ALLOW_ALL_SCHEMES; 
        UrlValidator validator = new UrlValidator(null, null, options);
        assertTrue(validator.isValid("f://class.com"));
        assertTrue(validator.isValid("file://class.com"));
        assertTrue(validator.isValid("https://class.uk"));
        assertTrue(validator.isValid("http://class.com"));
        assertTrue(validator.isValid("ftp://class.org"));
        assertTrue(validator.isValid("cs362://class.com"));
        assertTrue(validator.isValid("lsjlkjldkjf://class.com"));
	}
	//Allow local url 
	@Test
	public void testValidAllowLocal() {
	
        UrlValidator validator = new UrlValidator(UrlValidator.ALLOW_LOCAL_URLS);
        assertTrue(validator.isValid("http://localhost"));
        assertTrue(validator.isValid("https://localhost:80"));
        assertTrue(validator.isValid("http://google.com"));
        
	}
	@Test
	public void testValidDontAllowLocal() {
	
        UrlValidator validator = new UrlValidator();
        assertFalse(validator.isValid("http://localhost"));
        assertFalse(validator.isValid("https://localhost:80"));
        assertTrue(validator.isValid("http://google.com"));
        
	}
	@Test
	public void testValidAllowFragments() {
		 
        UrlValidator validator = new UrlValidator();
        assertTrue(validator.isValid("http://google.com/print#print"));
		assertTrue(validator.isValid("https://google.com/status#status"));
		assertTrue(validator.isValid("https://google.com/mail#mail"));
		assertTrue(validator.isValid("http://www.google.com/mail#Frag"));
        
	}
	@Test
	public void testValidNoFragments() {
		 
        UrlValidator validator = new UrlValidator(UrlValidator.NO_FRAGMENTS);
        assertFalse(validator.isValid("http://example.com/?color=#ffff&amp;shape=circle"));
		assertFalse(validator.isValid("https://google.com/status#status"));
		assertFalse(validator.isValid("https://google.com/mail#mail"));
		assertFalse(validator.isValid("http://www.google.com/mail#Frag"));
	}
	@Test
	public void testValidALLOW_2_SLASHES() {
		
		UrlValidator validator = new UrlValidator(UrlValidator.ALLOW_2_SLASHES);
		assertFalse(validator.isValid("http://google.com///cs362"));
		assertTrue(validator.isValid("https://google.com"));
		assertTrue(validator.isValid("https://google.com/cs362"));
	}
		
}

