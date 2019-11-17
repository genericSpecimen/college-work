<%@ page contentType="text/html" %>
<%@ taglib prefix="t" uri="/WEB-INF/mylib" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
    <body>
        <h4>Usage of custom tag &lt;t:reverse input="..."&gt; with mandatory input attribute</h4>

        <form method="POST">
            Enter a string: <input type="text" name="str" value="<c:out value="${param.str}"/>"> <br>
            <input type="hidden" name="submitted" value="true">
            <input type="submit" value="Submit">
        </form>
        <c:if test="${param.submitted}">
            <t:reverse input="${param.str}" />
        </c:if>
    </body>
</html>