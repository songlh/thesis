<?xml version="1.0"?>
<!DOCTYPE stylesheet>

<xsl:stylesheet
  version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  >

  <xsl:output
    method="text"
    encoding="ascii"/>


  <!-- bounded number of predictors to emit, if nonempty -->
  <xsl:param name="limit"/>


  <!-- sequence of predictors, optionally bounded in length -->
  <xsl:template match="scores">
    <xsl:apply-templates select="predictor[$limit = '' or position() &lt;= $limit]"/>
  </xsl:template>


  <!-- row for a single retained predictor -->
  <xsl:template match="predictor">
    <!-- fetch associated static information -->
    <xsl:variable name="index" select="number(@index)"/>
    <xsl:variable name="info" select="document('predictor-info.xml', .)/predictor-info/info[$index]"/>
    <xsl:if test="count($info) != 1">
      <xsl:message terminate="yes">
	<xsl:value-of select="concat('fatal error: cannot find unique static information for predictor #', $index)"/>
      </xsl:message>
    </xsl:if>

    <!-- effective bug-o-meter -->
    <xsl:apply-templates select="bug-o-meter"/>
    <xsl:text> &amp; </xsl:text>

    <!-- predicate -->
    <xsl:text>\lstinline$</xsl:text>
    <xsl:value-of select="$info/operand[1]/@source"/>
    <xsl:text> </xsl:text>
    <xsl:value-of select="document('schemes.xml', .)/schemes/scheme[@id = $info/@scheme]/predicate[$info/@predicate]/@text"/>
    <xsl:if test="$info/operand[2]">
      <xsl:text> </xsl:text>
      <xsl:value-of select="$info/operand[2]/@source"/>
    </xsl:if>
    <xsl:text>$ &amp; </xsl:text>

    <!-- function -->
    <xsl:text>\lstinline$</xsl:text>
    <xsl:value-of select="$info/@function"/>
    <xsl:text>$ \\&#10;</xsl:text>
  </xsl:template>


  <!-- a single Bug-O-Meter -->
  <xsl:template match="bug-o-meter">
    <xsl:variable name="width" select="@log10-true"/>
    <xsl:text>\bugometer{</xsl:text>
    <xsl:value-of select="$width"/>
    <xsl:text>}{</xsl:text>
    <xsl:value-of select="@context"/>
    <xsl:text>}{</xsl:text>
    <xsl:value-of select="@lower-bound"/>
    <xsl:text>}{</xsl:text>
    <xsl:value-of select="@fail - (@context + @lower-bound)"/>
    <xsl:text>}{</xsl:text>
    <xsl:value-of select="1 - @fail"/>
    <xsl:text>}</xsl:text>
  </xsl:template>

</xsl:stylesheet>
