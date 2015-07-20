<?php

/**
 * @file
 * This template handles the layout of Social Feed for JKNR Pane.
 *
 * Variables available:
 * - $social_feeds: An array of the social feeds.
 */
?>

<div class="socialmedia-panes-wrapper">
  <ul>
    <?php foreach ($social_feeds as $feed_group): ?>
      <li class="<?php echo $feed_group['class']; ?>">
        <div class="icon"><?php echo $feed_group['icon']; ?></div>
        <div class="feeds">
          <?php foreach ($feed_group['data'] as $row): ?>
            <?php echo $row; ?>
          <?php endforeach ?>
        </div>
      </li>
    <?php endforeach ?>
  </ul>
</div>
