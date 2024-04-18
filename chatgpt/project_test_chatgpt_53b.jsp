<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Employee ID</title>
</head>
<body>
    <%
        // Get the user id from the request parameter
        String userId = request.getParameter("eid");
        
        // Check if the user id is not null and not empty
        if(userId != null && !userId.isEmpty()) {
            // Escape special characters to prevent XSS
            userId = org.apache.commons.text.StringEscapeUtils.escapeHtml4(userId);
    %>
        <p>Employee ID: <%= userId %></p>
    <%
        } else {
    %>
        <p>No employee ID provided.</p>
    <%
        }
    %>
</body>
</html>
