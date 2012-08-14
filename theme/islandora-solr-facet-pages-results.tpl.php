<?php

/**
 * 
 */
?>

<ul class="islandora-solr-facet-pages-results">
  <?php foreach ($results as $result): ?>
    <li>
      <?php $filter = $solr_field . ':"' . $result['value'] . '"'; ?>
      <?php print l(truncate_utf8($result['value'], 72, TRUE, TRUE), 'islandora/solr/search/*:*', array('query' => array('f' => array($filter)))); ?>
      <span class="bucket-size">(<?php print $result["count"]; ?>)</span>
    </li>
  <?php endforeach; ?>
</ul>