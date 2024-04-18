// error.jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://www.springframework.org/tags" prefix="spring" %>
<html>
<head>
    <title>Hello Page</title>
</head>
<body>
    <h1>Hello!</h1>
    <spring:message code="errorMsg" />
</body>
</html>
