<%@ page contentType="text/html" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
    <body>
        <form action=5_vowels.jsp method="POST">
            <input type="hidden" name="submitted" value="true">
            Enter word: <input type="text" name="word" required="required" value="<c:out value="${param.word}"/>"> <br>
            Choose an option: <br>
            <input type="radio" name="oddeven" value="0">Even<br>
            <input type="radio" name="oddeven" value="1">Odd<br>
            <input type="submit" value="Submit">
        </form>

        <c:if test="${param.submitted}">
            <c:choose>
                <c:when test="${param.oddeven != 0 && param.oddeven != 1}">
                    <c:out value="Please choose a valid option!" />
                </c:when>

                <c:otherwise>
                    <c:set var="word" value="${param.word}" />
                    <c:choose>
                        <c:when test="${param.oddeven == 0}">
                            <c:out value="even" />
                            <c:set var="i" value="0" />
                        </c:when>
                        <c:when test="${param.oddeven == 1}">
                            <c:out value="odd" />
                            <c:set var="i" value="1" />
                        </c:when>
                    </c:choose>

                    <c:set var="success" value="true" />
                    <c:forEach var="j" begin="${i}" end="${fn:length(word)}" step="2">
                        <c:set var="ch" value="${fn:substring(word, j, j+1)}" />
                        <c:if test="${!fn:containsIgnoreCase('aeiou', ch)}">
                            <c:set var="success" value="false" />
                        </c:if>
                        <c:out escapeXml="false" value="${fn:substring(word, j, j+1)} &nbsp;" />
                    </c:forEach>

                    <c:choose>
                        <c:when test="${success == 'true'}">
                            <h1>You win!</h1>
                        </c:when>
                        <c:otherwise>
                            <h1>You lose!</h1>
                        </c:otherwise>
                    </c:choose>
                </c:otherwise>
            </c:choose>
        </c:if>

    </body>
</html>