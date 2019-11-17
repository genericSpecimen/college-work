<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
    <h2> <c:out value="Hello ${sessionScope.username}!"/> </h2>
    <body>
        <c:out value="You've bought the following items:" /> <br>
        <c:forEach items="${paramValues.itemstobuy}" var="i">
            <c:out escapeXml="false" value="${i} <br>"/>
        </c:forEach>
    </body>
</html>
