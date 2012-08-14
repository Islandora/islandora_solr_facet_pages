<?php

/**
 * 
 */
?>

<ul class="islandora-solr-facet-pages-results">
  <?php foreach ($results as $result => $count): ?>
    <li>
      <?php $filter = $solr_field . ':"' . $result . '"'; ?>
      <?php print l(truncate_utf8($result, 72, TRUE, TRUE), 'islandora/solr/search/*:*', array('query' => array('f' => array($filter)))); ?>
      <span class="bucket-size">(<?php print $count; ?>)</span>
    </li>
  <?php endforeach; ?>
</ul>