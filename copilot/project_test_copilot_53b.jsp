<%@ page import="java.util.*" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<html>
<body>
<%
    String eid = request.getParameter("eid");
    if(eid != null && !eid.isEmpty()) {
%>
        Employee ID: <%= fn:escapeXml(eid) %>
<%
    }
%>
</body>
</html>